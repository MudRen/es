//
// File: flock.c
// Creator: Robocoder@TMI-2
//
// Revision history:
//   06-22-93 - robo - created
//   06-25-93 - robo - optimizations; remove_stale_locks() no longer needed
//   06-25-93 - robo - replaced array deletion code with exclude_array()
//   ??-??-93 - ???? - added DEBUG_FLOCK code to track down a suspected bug
//   08-25-93 - robo - kludge to reuse an unfreed editor lock
//                   - removed DEBUG_FLOCK code
//
// File locking mechanism/server
// Based on code in /cmds/file/_ed.c by Buddha.

#include <flock.h>
#include <logs.h>
#include <commands.h>
#include <uid.h>

// Uses 2 arrays rather than a mapping for the ease in searching for
// either the file or the lockobj (player/object that locked the file).
// It's difficult to keep the lists accurate, but not impossible to handle:
//   o  multiple logins of the same character
//   o  one object may have many locks
//   o  stale locks from link-deaths

string *files, *lockobjs;

// A special mapping tracks a file's timestamps and previous object
// for logging and resource tracking (see below).

mapping filestats;

// To enable logging:
//   #define FILE_LOG in $(MUDLIB)/include/logs.h

// For more selective logging, #define NON_CRITICAL_PATHS
// in $(MUDLIB)/include/flock.h.
// This should be a list of paths that _should not_ be logged.
// For example,
//   #define NON_CRITICAL_PATHS "/tmp/","/open/","/ftp/"
// Note: the leading and trailing slashes, the quotes around each top level
//   path, and the commas for delimeters.

// prototypes for local functions
void log_change(string pathname, string flag);
string query_file_change(string pathname);
int get_timestamp(string pathname);

#define PUBLIC
#define  static

PUBLIC void create() {
    seteuid(ROOT_UID);
    files = ({ });
    lockobjs = ({ });
    filestats = ([ ]);
}

/*
 * flock()
 *   If mode == F_LOCK, attempt to gain a file lock.
 *   If mode == F_UNLOCK, attempt to remove a file lock.
 *   Returns 1 if successful, 0 otherwise.
 */
PUBLIC int flock(string pathname, int mode) {
    int position;
    object tobj, locker;

    // sanity checks
    //   if the arrays are off, then reset them,
    //   and pray nothing [else] goes wrong...
    if (sizeof(lockobjs) != sizeof(files)) create();
    //   reject bad pathnames, i.e. null or a null string
    if (!pathname || pathname == "") return 0;

    locker = this_player();
    if (!this_player() || !geteuid(this_player()))
        locker = previous_object();

    if (mode == F_LOCK) {
        position = member_array(pathname, files);
        if (position != -1) {
            // sanity check
            //   file is already locked...let's see if the lock is stale

#ifdef FILE_LOG
            if (!lockobjs[position]) {
                log_change(pathname, "Uh-Oh");
                return 0;
            }
#endif

            // who own's the lock, and is he/she still online?
            tobj = find_object(lockobjs[position]);
            if (tobj && tobj->query_linkdead()) {
                // Ok, just re-assign lock
                lockobjs[position] = file_name(locker);
                return 1;
            } else {
#ifdef REUSE_ED_LOCK_KLUDGE
                // Allow a user to reuse an editor lock under special conditions
                if (locker == tobj && files[position] == pathname
                      && file_name(previous_object()) == CMD_ED
		      && filestats[pathname]["prevobj"] == CMD_ED
                      && !in_edit(locker)) {
                    return 1;
                }
#endif
                // File busy
                return 0;
            }
        }
        lockobjs += ({ file_name(locker) });
        files += ({ pathname });
        filestats[pathname] =
              ([ "timestamp" : get_timestamp(pathname),
		 "prevobj" : file_name(previous_object()) ]);

    } else if (mode == F_UNLOCK) {
        position = member_array(pathname, files);
        if (position == -1) {
            return 0;
        }

        // check owner of lock
        if (this_player()
              && file_name(locker) != lockobjs[position]
	      && !member_group(geteuid(locker), "admin")) {
#ifdef FILE_LOG
            // Hmm...naughty, naughty...
            log_change(pathname, "***");
#endif /* FILE_LOG */
            return 0;
        }

        // remove lock
#ifdef FILE_LOG
        log_change(pathname, query_file_change(pathname));
#endif /* FILE_LOG */

        filestats[pathname] = ([ ]);
        map_delete(filestats, pathname);
        files -= ({ pathname });
        lockobjs = exclude_array(lockobjs, position);
    } else {
        // unrecognized mode
        return 0;
    }
    return 1;
}

/*
 * free_lockobj()
 *   Frees all locks associated with a player.
 *   Note: this function is called by /std/user.c
 */
PUBLIC void free_lockobj(object player) {
    int position;
    string tstr;
    string pathname;

    tstr = file_name(player);
    while ((position = member_array(tstr, lockobjs)) != -1) {
        pathname = files[position];
        if (in_edit(player)
	      && filestats[pathname]["prevobj"] == CMD_ED) {
            call_other(CMD_ED, "done_editing");
            continue;
        }
#ifdef FILE_LOG
        log_change(pathname, query_file_change(pathname));
#endif /* FILE_LOG */

        filestats[pathname] = ([ ]);
        map_delete(filestats, pathname);
        files -= ({ files[position] });
        lockobjs = exclude_array(lockobjs, position);
    }
}

/*
 * query_lockobj()
 *   Returns the object that owns that lock on "file"
 */
PUBLIC object query_lockobj(string file) {
    int i;

    if (!file || file == "") return 0;

    i = member_array(file, files);
    if (i != -1) {
        return find_object(lockobjs[i]);
    }
    return 0;
}

/*
 * query_lockfn()
 *   Returns the name of _a_ file associated with the locking object.
 */
PUBLIC string query_lockfn(object locker) {
    int i, j, k;
    string s, t;

    if (!locker) return 0;

    s = file_name(locker);
    j = sizeof(lockobjs);
    k = member_array(s, lockobjs);
    if (k != -1) {
        for (i = k; i < j; i++) {
            t = files[i];
            if (s == lockobjs[i]
		  && filestats[t]["prevobj"] == file_name(previous_object()))
                return t;
        }
    }
    return 0;
}

/*
 * get_timestamp()
 *   Returns the timestamp of a file, or 0 if the file doesn't exist.
 */
 int get_timestamp(string pathname) {
    mixed *stats;
    int position;
    int stamp;

    if (file_size(pathname) >= 0) {
        stats = stat(pathname);
        stamp = stats[1];
    } else
        stamp = 0;
    return stamp;
}

/*
 * query_file_change()
 *   Returns a string that identifies the manner by which a file was changed.
 */
 string query_file_change(string pathname) {
    mixed *stats;
    int position;
    int oldstamp, newstamp;

    if ((position = member_array(pathname, files)) == -1)
        return 0;
    newstamp = get_timestamp(pathname);
    oldstamp = filestats[pathname]["timestamp"];

    if (oldstamp != newstamp) {
        if (oldstamp) {
            if (newstamp)
                return "!"; // changed
            else
                return "-"; // purged
        } else
            return "+";     // added
    }
    // else file not changed or not created
    return 0;
}

#ifdef FILE_LOG
/*
 * log_change()
 *   Logs file changes to the log file $(FILE_LOG).
 */
 void log_change(string pathname, string flag) {
    string s;

#ifdef NON_CRITICAL_PATHS
    string *paths;
    int i, k, x;

    if (!flag || flag == "")
        return;

    paths = ({ NON_CRITICAL_PATHS });
    if (this_player()) {
        paths += ({ user_path(geteuid(this_player())) });
    }

    x = sizeof(paths);
    for (i = 0; i < x; i++) {
        s = paths[i];
        k = strlen(paths[i]);
        if (k <= strlen(pathname) && s == pathname[0..k-1]) {
            // don't log this one
            return;
        }
    }
#else
    if (!flag || flag == "")
        return;
#endif /* !NON_CRITICAL_PATHS */

    if (this_player())
        s = geteuid(this_player());
    else
        s = file_name(previous_object());
    if(this_player())    
    log_file(FILE_LOG, wrap(s + " " + flag + " \"" + pathname +
          "\" [" + extract(ctime(time()), 4, 15) + "]"));
}
#endif /* FILE_LOG */

/*
 * dump_locks()
 *   A debugging function that prints out a list of outstanding locks--
 *   filename, lock owner, timestamp of file.
 */
PUBLIC void dump_locks() {
    int i, j, k;
    string tstr, tstr2;
    object tobj;

    i = sizeof(lockobjs);
    j = sizeof(files);
    k = sizeof(filestats);

    if (i != j) {
        if (i < j)
            j = i;
        write("Hmm...array inconsistency.\n");
    }
    if (i != k) {
        write("Hmm...mapping inconsistency.\n");
    }

    for (i = 0; i < j; i++) {
        if (lockobjs[i]) {
            tobj = find_object(lockobjs[i]);
            if (tobj) {
                tstr = capitalize(geteuid(tobj));
                tstr += " (" + lockobjs[i] + ")";
            } else
                tstr = lockobjs[i];
            tstr2 = files[i];
            if (k = filestats[tstr2]["timestamp"])
                printf("%20s\t%s\t%s\n", tstr, tstr2, ctime(k));
            else
                printf("%20s\t%s\t[New File]\n", tstr, tstr2);
        } else {
            write("Hmm...invalid entries.\n");
        }
    }
}
