
#include "../goomay.h"

inherit Army;
int key =0;
void create ()
{
        ::create();
        set_name( "Captain of Policeman", "段飞鹰" );
        add ("id",({ "captain","policeman","cop"}));
        set_short( "段飞鹰");
		set("level",13);
        set("unit","个");
        set_long(
@C_LONG
你看到一个高大强壮的人，他的年纪大约四十来岁，满脸精干警觉的神
色，他就是本镇的捕头－段飞鹰。他最大的兴趣就是升官发财加拷打犯
人，他是一个认为只有重刑才能破案的人。
C_LONG
);
        set ("gender", "male");
        set ("race", "orc");
        set_natural_armor( 70, 25 );
        set_natural_weapon( 30, 15, 30 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_skill( "unarmed", 100 );
        set_skill( "parry", 100 );
        set("alt_corpse","NONE");
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
		"key"  : "@@ask_key",
                "jail" : "@@ask_key",
        ]) );

}

int ask_key()
{
        object me ;
        me=this_player();
   if( (int)me->query_quest_level("Goddess_statue") < 2 ){
	if (key)
	{
	tell_object(me,
        "段飞鹰道：「英雄阁下 !! 我已经把钥匙给人了。」\n");
	return 1;
	}
	else
	{
        tell_object(me,
        "段飞鹰道：「原来是力战妖怪的英雄 !! 钥匙在这里。」\n");
	key=1;
	new(Obj"key1")->move(this_object());
	command("give key to "+this_player()->query("name"));
        return 1;
	}
	}
        else
        {
        tell_object(me, 
"段飞鹰瞪著你道：「去 !! 去 !! 去 !! 没事来问牢房钥匙做什麽？你要劫狱吗？」\n"
			);
                return 1;
}
}

void die()
{
 tell_room( environment(this_object()),
@C_DIE

段飞鹰突然对著你的背後大叫：「你们来的正好，把这个小子给我抓起来」
你回头一看，发觉受骗了，等你再转头回来，段飞鹰已经跑的不见踪影了。

C_DIE
 ,this_object() );

	::die(1);                
}

void reset()
{
	key=0;
}
