#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(19);
        set_name( "Thief Arcold", "��͵ �ǿ�" );
        add ("id", ({ "arcold","thief"}) );
        set ("class","theif");
        set_short( "��͵ �ǿ�" );
        set_long(@C_LONG
�㿴��һ������ʮ�ֿɰ�����Ů�����ʮ�߰������ҵ���ͣ�ȫ������ɫ
��װ���������������⺷�汸������ע�⵽����������һֻ��Ϊ�����Ľ�ɫ
���꣬�ѵ���ʧ���Ծõ���������
C_LONG
        );
        set( "race", "imp" );
        set( "gender", "female" );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 24 );
        set_perm_stat( "pie", 17 );
        wield_weapon("/d/island/obj/dagger01.c");
        equip_armor(ARMOR"god_3.c");
        equip_armor(ARMOR"black_suit.c");
        set_perm_stat( "int", 20 );
        set_skill( "dodge", 90 );
        set_skill( "anatomlogy", 100);
        set("aiming_loc","weakest");
        set("player_invisible", 1 );
        set( "aim_difficulty",([ "weakest":15,"vascular":30,"ganglion":50
]) );
        set( "special_defense",([ "all":30, "evil": 40 ]) );
        set_natural_armor(15,20);
        set_natural_weapon( 40, 17, 26 );
        set( "wealth/silver", 200);
        set("alt_corpse",WEAPON"dagger01.c");
        set( "moving", 1 );
        set( "speed", 30 );
        set( "patrol", ({ "west", "south", "south", "east",
                  "east", "north","north", "west", "south",
		"west", "north", "east" }) );
}

void init()
{
        object ob;
        ::init();
        if( !(ob= this_player()) || !userp(ob) ) return;
        call_out( "backstab", 0, ob );
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

void backstab(object ob)
{
        string *types;
        object env;
        int i, total;

        env = environment();
        if( !env || !present(ob, env) ) return;
        tell_object( ob,
"
�ǿ�ͻȻ���㱳��ð����˫��ɱ�����أ����������곯�㱳��û�з���
���ĵط��ݺݵĴ�����ȥ����е�һ���ʹ���ƺ��ǿܵı��������ܵ���
�൱����˺�
\n");
        ob->receive_special_damage( "evil" , 30 + random(20));
        report(ob,ob);
}

void die()
{
        object killer,dagger;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/arcold",1);
        dagger = present( "golden dagger", this_object() );
        dagger->remove();
        ::die(1);
        set( "death_msg","%s\n");
        tell_room(environment(),
"
����˵Ĵ��ǿܵ�ʬ�����ó���������������꣬�������ϰ��棬����
�������ķ�â���ף�����Ȳ��ϴ�˵�е������꣬����ϸ��������ѱ�
�꣬�ۣ�����Ľ�ɫӣ����Ȼ�Ƕƽ��....

һ��֮�����ְѱ��궪������\n\n");
	set("alt_corpse",WEAPON"dagger01.c");
}
