
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
     set_level(22);
     set_name("guard", "����");
     set_short("the cool guard", "��֮����");
        set_long(
                "ӵ��а������������,���з������µ�а��.\n"
                "��ʥ�������������ñ���.\n",
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_skill( "thrusting", 100 );
        set( "alignment", 10000 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_weapon( 50, 15, 30 );
        set_natural_armor( 90, 60 );

        wield_weapon( "/d/knight/fortress/weapons/dragonblood" );
}
