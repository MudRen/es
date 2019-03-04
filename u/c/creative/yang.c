#include <mudlib.h> 
#include <ansi.h>
inherit TEACHER;
inherit MONSTER;

void create ()
{
        ::create();
        seteuid( getuid() );
        set_level(18);
        set_name( "yangsix", "������" );
        add ("id", ({ "yang","six"}) );
        set_short( "ǹ�� ������" );
        set_long( @LONG
    ���ý�ü��Ŀ,��������,��cool������,������˼��ңԶ�Ķ�����½�ؽ���Ƹ
���̵���ʿǹ�����ڹ��ĸ���,�����ĵȼ����߿���������һЩ����train����
LONG        );
        set( "alignment", 10000 );
    set( "gender", "male" );
    set( "race", "human" );
        set( "unit", "��" );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "con", 27 );
        set_perm_stat( "piety", 30 );
        set_perm_stat( "karma", 21 );
        set("max_hp", 3500);
        set("hit_points", 3500);
        set("wealth", ([ "gold": 3000 ]) );
        set_natural_weapon( 45, 25, 55 );
        set_natural_armor( 35, 30 );
    set("weight", 800);
    set("exp_reward",59000 );
    set_experience(450000);
    set_skill("parry",100);
    set_skill("block",100);
    set_skill("dodge",100);
    set_skill("jousting",100);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
        wield_weapon( "/d/knight/fortress/weapons/dragonblood" );
        equip_armor( "/d/knight/fortress/armors/silver_plate" );
        equip_armor( "/d/knight/fortress/armors/silver_leggings" );
        equip_armor( "/d/knight/fortress/armors/silver_gauntlets" );
        equip_armor( "/d/knight/fortress/armors/silver_shield" );
        equip_armor( "/d/knight/fortress/armors/silver_boots" );
        equip_armor( "/d/knight/fortress/armors/silver_helmet" );
   set( "chat_chance", 12 );
   set( "chat_output", ({
         "������̾��: ��û��ѧ�����Խ�, ������!\n" }) );
    set( "inquiry", ([
            "���ǹ" : "@@ask_lance",
            "train" : "@@ask_train" ]) );
    set("tactic_func", "special_attack"); 
    set_lessons( ([
                "inner-force" : ({ 200, 50 }),
                "dodge" : ({ 200, 50 })
    ]) );
}

void init()
{
   npc::init();
   teacher::init();
}

void ask_lance( object who )
{
    tell_object( who, 
      "����˵: ����������, ��ҵ���ϰ������������, \n"
      "        �����������������û��(job)��\n" 
    );
}

// 10% use it! damage 40-50.
int special_attack()
{
    object *victim;
    int i;
    if( !(victim = query_attackers()) || (random(10)>1) ) return 0;
    tell_room( environment( this_object() ), 
      "\n�����ɴ�: ���ҵľ��� ���ն! \n"+
      "ֻ�������ɰ�ǹһ�Σ������������͵ĹⲨ�����е�����ȥ��\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+40);
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}
int check_trainee(object who)
{
    if( (string)who->query("class")=="knight" &&
        (int)who->query_level()>18 )
    return 1;
    else return notify_fail(
      "������˵: ��ֻ�̹��ʸ����ʿ��\n" );
}
