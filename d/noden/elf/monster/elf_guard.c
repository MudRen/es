#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "Elf guard", "��������" );
        add ("id", ({ "elf", "guard" }) );
        set_short( "��������" );
        set("unit","λ");
        set_long(
          "��������������𱣻����ԭ�ĺ�ƽ������λ��ǿ��սʿ�����������֮��\n"
        );
        set("max_hp", 1000);
        set("hit_points", 1000);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 19);
        set_perm_stat("pie", 19);
        set_perm_stat("kar", 25);
        set_natural_weapon( 42, 20, 40 );
        set_natural_armor( 80, 40 );
        set("gender", "male");
        set("wealth/gold",35);
        set("race", "elf");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"mail");
}
