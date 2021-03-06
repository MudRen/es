//black_chocobo.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
	::create();
	seteuid( getuid() );
   set_level(15);
   set_name( "chocobo", "陆行鸟" );
	add ("id", ({ "bird", "chocobo", }) );
   set_short( "陆行鸟" );
	set_long( @C_LONG
在地上活泼地跑动的巨型鸟，最高时速可达三十五公里。生性十分温驯，
据说能够骑在它的背上旅行，不过你要先能抓住它。
传说它酷食任何东西。又如果你是它的主人, 它会帮你撞击(hit)敌人。
C_LONG
	);
   set( "alignment", 1000 );
    set( "unit", "只" );
   set_perm_stat( "dex", 25 );
   set_perm_stat( "str", 20 );
   set_perm_stat( "int", 13 );
   set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 25 );
   set_perm_stat( "karma", 25 );
   set_natural_weapon( 30, 10, 28 );
   set_natural_armor( 80, 35 );
   setenv( "C_MIN", "一只$N快速的跑了过来。");
        setenv( "C_MOUT", "$N飞快地往$D边跑走了。");
        set ("special_defense",
            ([ "all" : 20 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 10);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N正骑著一只陆行鸟。\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一脚踢在%s脸上", "%s一爪抓到%s",
                    "%s用大嘴啄%s", }) );
    set_c_limbs( ({ "身体", "翅膀", "嘴", "脚", "屁股", "爪子", }) );
    set( "c_death_msg", "%s说: 我咧#@!&$*? :( .... 然後就死了。\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "陆行鸟尖叫一声: GEEE....\n"
             "陆行鸟把"+item->query("c_name")+"吃下肚!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "陆行鸟滴下了一滩口水, 真脏啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你现在可以骑陆行鸟了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "陆行鸟尖叫一声: 又是你这杀人魔王，快逃!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "陆行鸟尖叫一声: 又是你这杀人魔王，快逃!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) ) 
        return notify_fail("陆行鸟不听你的指挥。\n");
   if( !arg ) return notify_fail("你想撞谁？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("这里没有那种东西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("撞自己？你疯啦？\n");
   if( !living(target) )
        return notify_fail("陆行鸟用力的撞了"
                        +target->query("c_name")+"但是什麽事也没发生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想撞谁？\n");
   if( !owner->query_vision() )
        return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
   if ( target->query("no_attack") )
        return notify_fail("这家伙－不能杀。\n");
   if( userp(target) && (int)target->query_level()< 5 )
        return notify_fail("你不能 PK 他 !!\n");
   if( "berserk" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( "melee" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交谈能力太低了!\n" );
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n你命令陆行鸟向对方撞去, 但是敌人闪过了!\n\n" );
        tell_object( target,
             "\n陆行鸟向你撞来, 但是你闪过了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著陆行鸟撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n你命令陆行鸟向对方撞去, 敌人摔倒在地上了!\n\n" );
        tell_object( target,
            "\n陆行鸟向你撞来, 你摔倒在地上了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著陆行鸟撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你现在摔倒在地，无法攻击！ )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
