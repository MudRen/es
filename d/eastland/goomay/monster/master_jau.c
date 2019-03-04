
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Jau", "赵堂主" );
        add ("id",({ "jau","master"}));
        set_short( "赵堂主");
        set("unit","位");
        set_long(
@C_LONG
这里坐著一个铁塔一般的大汉，他的面前摆\著两只酒杯，他正捧著一只
酒□子仔细的斟著酒，然後自己喝掉。你一路走过来，他只是用他那双
醉眼瞄著你，还是自斟自饮，好像一点都不把你放在眼里。
C_LONG
);
        set ("gender", "male");
        set ("race", "hawkman");
        set_natural_armor( 90, 20 );
        set_natural_weapon( -5, 5, 15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "blunt", 100 );
        set_skill( "parry", 100 );
        set( "hit_points", 800 );
        set( "max_hp", 800 );
        set( "special_defense", ([ "all": 20 ]) );

        set( "wealth/gold", 100 );
        wield_weapon( Obj"thor_hammer" );
        equip_armor( Obj"thor_gloves" );

        set( "inquiry", ([
                "wine" : 
@WINE
「酒？你也懂酒？俺老赵这辈子喝遍了各种好酒烈酒，可以说
是老酒虫了，还有什麽酒没喝过？不过听说最近有人从海外带来一些新酒，
好像叫什麽加的，听说烈的很 !! 嘿嘿 !! 老子就想试试 ...」
WINE
]) );

}

int accept_item(object me,object item)
{
        string name;
        object obj;
        int i;

	name = (string) item->query("name") ;
	if ( name !="vodka" ) {
	tell_object(me,
		"赵堂主摇摇头：「谢谢 !! 老赵我不需要这东西 !!」\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

        i = this_player()->query_temp("give_wine");
        if ( i )
                this_player()->set_temp("give_wine",i+1);
        else
                this_player()->set_temp("give_wine",1);
        if (i != 2){
                command("drink vodka");
                tell_room( environment(), 
                "赵堂主红著脸，满意的咂咂嘴笑道：好酒 !! 你还有吗？\n");
	}
        else {
        command("drink vodka");
        tell_room( environment(), 
        "赵堂主醉的在地上满地乱爬，大笑道：真过瘾 !! 你也尝尝我老赵的好酒 !!\n" );
        me->delete_temp("wine");
        obj=new(Obj"old_wine");
        obj->move(this_object());
        command("give wine to "+(string)me->query("name"));
        me->set_explore("eastland#13");
	}
	return 1;
}
