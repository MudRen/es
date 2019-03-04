
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(10);
        set_name( "Rich man", "֣��" );
        add ("id", ({ "draconian", "man","rich" }) );
        set_short(" ֣��");
        set("unit","λ");
        set("alignment",-100);
        set("weight",1000);
        set("wealth/gold",400);
        set_long(
           "֣���ǵ��³�������Ǯ���ˣ����Ŀ�ͷ����:����ʲ�ᶼû�о���Ǯ�ࡣ\n"
        );
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 60);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 30);
        set ("natural_armor_class", 70);
        set ("special_defense",(["all":60,"none":60]));
        set ("gender", "male");
       
        equip_armor(Lditem"boots");
        wield_weapon(Lditem"longsword2");
        set_perm_stat("str", 30);
        set_perm_stat("dex", 5);
        set_perm_stat("kar",30);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}       
