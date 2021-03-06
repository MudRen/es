#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(19);
        set_name( "Thief Arcold", "神偷 亚寇" );
        add ("id", ({ "arcold","thief"}) );
        set ("class","theif");
        set_short( "神偷 亚寇" );
        set_long(@C_LONG
你看到一名长得十分可爱的少女，大概十七八岁左右的年纪，全身穿著黑色
劲装，看起来清秀与剽悍兼备，你又注意到她手上拿了一只极为罕见的金色
扁钻，难道是失传以久的镶金扁钻吗？
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
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
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
亚寇突然从你背後冒出，双眼杀机重重，手拿著扁钻朝你背後没有防备
到的地方狠狠的刺了下去，你感到一阵剧痛，似乎亚寇的背刺让你受到了
相当大的伤害
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
你高兴的从亚寇的尸体中拿出金光闪闪的镶金扁钻，拿在手上把玩，用手
试试它的锋芒，咦，好像比不上传说中的镶金扁钻，你仔细地瞧瞧这把扁
钻，哇！上面的金色樱花竟然是镀金的....

一气之下你又把扁钻丢到地上\n\n");
	set("alt_corpse",WEAPON"dagger01.c");
}
