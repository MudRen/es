#include <races.h>
inherit RACE_LIZARDMAN;

void create()
{
        ::create();
        set_level(15);
        set_name( "holy guard","ʥ������" );
        add ("id", ({ "guard" }) );
        set_short( "ʥ������");
        set("unit","λ");
        set("alignment",400);
        set("wealth/gold",50);
        set_long(
"�㿴��һλʥ����������̬ׯ�����µ������������\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",25);
        set_perm_stat("str",25);
        set_natural_weapon( 50, 12, 42 );
        set_natural_armor( 78, 12 );
        set ("gender", "male");
        set("special_defense",(["all":10,"none":10]));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
	equip_armor("/d/eastland/tomb/armors/shoes1");
}
