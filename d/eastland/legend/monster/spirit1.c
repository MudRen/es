#include "../legend.h"
#include "../magic.c"

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "wood spirit","神木上人" );
	add ("id", ({"spirit"}) );
	set_short("神木上人");
	set_long(@C_LONG
你眼前所见是一位面目慈祥，和霭可亲的老者。虽然，他看起来约有六、七十岁的
年纪，却感受不到任何苍老的讯息，反而带给你一种活泼的泉源。神木上人原本是
天界的仙人，但八百年前犯了过错因而被贬下凡间，他似乎遇到麻烦了，因而眉目
深锁。
C_LONG
	);
        set("be_asked",0);
	set("unit", "名" );
        set("no_attack",1);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        set( "inquiry", ([
             "mistake":"@@ask_mistake",
             "过错":"@@ask_mistake",
             "trouble":"@@ask_mistake",
             "麻烦":"@@ask_mistake"
        ]) );
}
void ask_mistake( object asker )
{
     object lock;
     if ( query("be_asked") ) {
        tell_room(environment(this_object()),
         "神木上人说道:我把铁锁交给别人了，希望你们一们合力消除了「无支祈」。\n");
        return ; 
     }
     set("be_asked",1);
write(@C_LONG
神木上人叹道:八百年前，我一时疏乎把水怪「无支祈」给放出，因此被贬下凡间。
 　　　　　　一直以来，因为我神功未成，屡次挑战「无支祈」都没办法使那支畜
 　　　　　　牲伏诛，希望你能帮助我。对了，当你杀死「无支祈」之後记得拿铁
 　　　　　　锁 ( iron_lock ) 它，不然它又会活过来。大恩不言谢。

神木上人从身上掏出一件大铁锁。
C_LONG
      );
      lock=new(LITEM"iron_lock");
      lock->move(environment(this_object()));  
      call_out("recover",300,this_object());
}
void recover(object obj)
{ obj->set("be_asked",0);}
