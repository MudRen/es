/*
Wed  07-06-94
People counter..
*/
 
#include <mudlib.h>;
#include <config.h>;
#include <daemons.h>;
 
inherit OBJECT;
 
void create();
void init();
int busy;
 
void create() {
  seteuid(getuid());
  set_name("counter","������");
  set_short("(invis)counter","(invis)������");
  set_long(
@LONG
some toy by elon.. to do some stats calculation..
this is an invisible item..
LONG
,
@C_LONG
look at English desc..
this is an invisible item...
C_LONG
);
	set("prevent_get",1);
    set("invisible",1);
	set("mass",1);
	set("bulk",1);
	busy=0;
}
 
void init() {
    string pname, prace, pgender, pguild,logstr, plevel, ptime;
    if ((int)this_player()->query_temp("counter") == 1) {
write_file("/open/elon/shop.log",(string)this_player()->query("name")+"\n");
        return;
    }
    this_player()->set_temp("counter",1);
    pname=(string)this_player()->query("name");
    plevel=(string)this_player()->query_level();
    prace=(string)this_player()->query("race");
    pguild=(string)this_player()->query("class");
    ptime=(string)WEATHER_D->query_game_time();
    logstr=sprintf("%12s : %2d : %10s : %12s : %s",pname, plevel, prace, pguild, ptime);
    write_file("/open/elon/counter.log",logstr+"\n");
    return;
}
