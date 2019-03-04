#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "Sleeping man", "昏睡在路边的人" );
    add( "id",({"man"}) );
    set_short( "昏睡在路边的人");
    set("no_attack",1);
    set_long(@C_LONG
一个喝醉酒倒在路边的人。他满身酒臭味,令你全身作呕,不过他似乎知道
某些事情,叫醒他说不定会吐露什麽哟!!!
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("alignment",1000);
    set("weight",300);
    set("hit_points",1);
    set("max_hp",1);
}        

void init()
{ add_action("do_slap","slap");}

int do_slap(string arg)
{
   object ob1;
     
   if ( arg=="man" ){ 
     if (this_player()->query_temp("button")){
        tell_object(this_player(),
"他说道:他妈的,吵什麽吵,再吵我打你喔。\n");
     }
     else {                                                            
       tell_object(this_player(),
"\n     唉哟,虾米大代志啦,人家睡得好好的!!说著他反身想睡,可是\n"
"又爬了起来,说道:哦,原来是我家那支母老虎叫你来的喔,拿去吧。\n\n"
       );
       ob1 = new(DITEM"button");
       ob1->move(this_object());
       this_player()->set_temp("button",1);
       command("give "+(string)ob1->query("name")+" to "+
       lower_case((string)this_player()->query("name")));
     } 
   }
     return 1;
}