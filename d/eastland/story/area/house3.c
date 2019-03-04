#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("屋子");
	set_long( @LONG
这里是「羽民族大首领  羽后」居住的小屋。屋子有木制成的桌子、椅子和一
张床，以及一篓篓装满著刚采下来和晒乾的葡萄的大型篮子。木桌上有放著几本书
，是「羽后」毕生学习魔法的心得。小屋中收拾的一尘不染，只不过是简单的摆设
。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "west" : SAREA"village2" 
        ]) );
        set("no_embattle",1);
        set("objects", ([
             "elder" : SMOB"elder1"
        ]) );
	reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( (int)random(3) > 1 )
        return ;
    this_player()->delete_temp("hidding");
        call_out("back",1,this_player());
}
void back(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
          "( 你潜行失败，被敌人突袭，一阵手忙脚乱！ )\n" );
}