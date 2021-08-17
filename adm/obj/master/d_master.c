//#pragma save_binary

// Buddha's new access checking system.  (4/10/93)
// This was put together on 4/10/93 using code from two things:
// a file called "/std/priv.c" that was started on 5-31-92, by Buddha,
// and Cynic's not-quite-functional domain security system, that
// was proving to be very frustrating to install.  At some point I
// realized that there were some important functional problems with
// what Cynic had left me to install and test, and ended up rewriting the
// lookup and storage methods to behave in the way that they should.

// This code is a part of the TMI-2 distribution mudlib, please don't
// use it for monetary gain.


#include <uid.h>
#include <filepriv.h>


mapping group_list, permission_list;

protected nomask string check_access(string file, string group);


void create() {
    //
    //  Edit the group_list mapping as fits your domain.
    //  Each member of the domain should have their own entry.
    //  The key should be their lower_case name, and the value
    //  should be the name of their domain-specific group, as
    //  defined below, in permission_list.
    //
    // Your typical entry will look like:
    //  "krishna"	: "admin",

    group_list = ([
        getuid()	: "objects", // these are the domain's objects
    ]);

    //
    //  Edit the permission_list mapping as fits your domain.
    //  All groups implicitly defined in the group_list mapping
    //  above must be explicitly defined here.  In addition, you
    //  must define the group "non-member" for eff_users who are
    //  not members of your domain group.
    //
    //  Each group's permissions are a mapping of relative paths
    //  in the form:  "xy/z", where 'x' is either "r" or "-"
    //  (indicating read permission for that group), 'y' is either
    //  "w" or "-" (indicating write permission), and 'z' is the
    //  path (relative to the domain directory's root) defined by
    //  the aforementioned permission flags 'x' and 'y'.
    //
    //  A typical group might look like:
    //  "admin"		: ([ "/" : "rw" ]),
    //  The default setting lets objects save in the data dir, and
    //  makes the domain globally readable.

    permission_list = ([
        "archwizard"	: ([ "/" : "rw" ]),
        "sage"			: ([ "/" : "rw", "adm" : "r-" ]),
        "objects"       : ([ "data" : "rw", "/" : "r-" ]),
        "non-members"	: ([ "/" : "r-" ]),
    ]);
}

//
//  valid_access()
//  The arg 'file' represents a relative path, not beginning with a "/".
//  The arg 'eff_user' represents the euid of the calling object.
//

nomask int valid_access(string file, string eff_user) {
    string group, perm;

    if (member_array(eff_user, keys(group_list)) == -1) group = "non-members";
    else group = group_list[eff_user];

    perm = check_access(file, group);
    switch(perm) {
    case "rw": return (READ | WRITE);
    case "r-": return (READ);
    case "-w": return (WRITE);
    case "--":
    default:   return NONE;
    }
    return NONE;
}


protected nomask string check_access(string tmp, string group) {
    int i;
    string *parts;

    // check for a direct match
    if (permission_list[group][tmp]) return permission_list[group][tmp];

    // there was no match, so let's split this string up into segments.
    parts = explode(tmp, "/");

    if (sizeof(parts) == 1) {
        // It looks as if we are trying to write to the domain's
        // root directory.  So, check if there is an entry for
        // this group, and if there isn't, use the default.
        return (permission_list[group]["/"] ?
            permission_list[group]["/"] :
            permission_list["non-members"]["/"]);
    }

    // okay, let's look for the closest match we can find for this,
    // starting with things most similar and working towards root.

    for (i=sizeof(parts)-1;i>=0;i--) {
        tmp = implode(parts[0..i], "/");
        if(permission_list[group][tmp]) {
            return permission_list[group][tmp];
        }
    }
    // Looks like we didn't find anything useful... oh well.
    return permission_list[group]["/"] ?
      permission_list[group]["/"] : permission_list["non-members"]["/"];
}

/* EOF */
