// chest.c
// A boring treasure chest. A basic container.
// Mobydick@TMI-2, October 1992.

#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {
	::create() ;
	set_name("stone chest", "ʯ����");
	set_short("ʯ����");
    add("id",({"chest"}));
// Containers have two long descriptions, one for open and one for closed.
	
	set_c_open_long("һ�����������ʯ����.\n");
	set_c_closed_long("һ�����������ʯ����.\n");
// Some containers are closeable: others are not. This controls it.
//	set( "prevent_get" , 1 );
	set_possible_to_close(1) ;
	set("weight", 30);
	set("max_load", 25);
	set ("value", ({ 3, "gold" }) );
// Each lock has a number which controls how much work is needed to fully
// lock it, and each key has a number which controls how much locking that
// key does in one command. "max_lock" is the total amount of locking that
// can be spent on this lock before it is fully locked.
// Usually the key has enough efficiency that the key can fully lock the
// lock with one command. But it doesn't have to be that way if you'd
// rather it wasn't.
	set("max_lock", 2);
// If lock=0, the object has no lock. If lock<0, it has a lock but is unlocked.
// If lock>0, the lock is locked to that degree of effort. Not to be greater
// than max_lock.
	set("lock", 2);
// The ident string of the key which opens the lock.
	set("key", "ECHO_DWARF_CITY_1") ;
    to_set_closed();    
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
	container::init();
	lock::init();
}
