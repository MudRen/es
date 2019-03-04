#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "law master","������" );
        add ( "id", ({ "master","law"}) );
        set_short("ִ������ ������" );
        set("unit","λ");
        set_long(@C_LONG
����ǰ��������һ����ɫ�������ľ����ǵ���ؤ�� ������һ����ò��Ȼ������λ
��ؤ���е�Ҫλִ������,����������˽,����һ�Ŵ�С�˵�,��Ȼ����Υ�������
��,������Ҳ�Ǿ������֡���ʹ����һ���йٱ�,�ڽ��������ж��֡�
C_LONG
        );
        set("weight",720);
        set("alignment",2500);
        set("wealth/silver",800);
        set("gender","male");
        set("race","human");
        set("hit_points",540);
        set("max_hp",540);
        set_perm_stat("str",23);
        set_perm_stat("int",25);
        set_perm_stat("dex",20);
        set_natural_weapon(30, 15, 20);
        set( "natural_weapon_class2", 30 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 20 );
        set_natural_armor(65,25);
        set( "special_defense", ([ "all": 25, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":40,"vascular":40,"ganglion":40 ]) );
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill( "thrusting", 90 );
        set_skill( "two-weapon", 90 );
        wield_weapon( "/d/eastland/haiwei/obj/pen" );
        wield_weapon2( "/d/eastland/haiwei/obj/pen" );
        equip_armor(DARMOR"turban");
        set( "inquiry", ([
                   "jail":"@@ask_jail",
                    "war":"@@ask_war"
            ]) );
        set("tactic_func","my_attack");
}
void ask_jail( object asker )
{
     if ( !asker->query_temp("keeper_finish2") )
        tell_object( asker ,
           "������˵��:С����û����ʲ�����,ȥȥȥ��\n");
     else {      
        asker->set_temp("jail_asked",1);
        tell_object( asker ,
           "������˵��:�ڴ��е�ĳ������(corner)��һ��·����ͨ��������\n"
           "           ������˵����,���������ʲ��,��Ҫ�������,��Ȼ\n"
           "           �һ�������ġ�\n"           
                ); 
     }
}
void ask_war()
{
write(@C_LONG
������������ɫ�ƺ���̫��˵��
C_LONG
     );
}