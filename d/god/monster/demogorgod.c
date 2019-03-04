#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "demogorgod", "����" );
        add ("id", ({ "demogorgod" }) );
        set_short("ħ��ս���ų�  ����");
        set_long(
                "��ɱ����һ�������������а����ˡ�\n"
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 100 );
        set_skill( "dodge", 100 );
        set_skill( "block", 100 );
        set( "alignment", 5000 );

        set( "race", "human" );
        set( "gender", "male" );

        set( "hit_points", 2500 );
        set( "max_hp", 2500 );
    set( "aim_difficulty",
        ([ "critical":60,"vascular":60,"weakest":60,"ganglion":60 ]) );
        set_natural_weapon( 50, 20, 30 );
        set_natural_armor( 90, 70 );
        set ("special_defense", ([
                "all": 40 , "none" : 50]) );

        wield_weapon( "/d/god/weapon/longblade" );
        equip_armor( "/d/god/armors/plate" );
        equip_armor( "/d/god/armors/leg" );
        equip_armor( "/d/god/armors/gauntlet" );
        equip_armor( "/d/god/armors/shield" );
        equip_armor( "/d/god/armors/boot" );
        equip_armor( "/d/god/armors/helm" );
}
