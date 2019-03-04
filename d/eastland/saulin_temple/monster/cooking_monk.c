#include "saulin_monka.c"

void create ()
{
        ::create();
        set_level(9);
        set_name( "Cooking monk", "�Ƴ�ʦ��" );
        add ("id", ({ "monk","cooking" }) );
        set_short("�Ƴ�ʦ��");
        set("unit","λ");
        set_long(
           "����һλǿ׳�ĺ��У�����ְ���Ǹ���ȫ�µĻ�ʳ��\n"
        );
        set("alignment",200);
        set("wealth/silver",50);
        set_perm_stat("str", 15);
        set_perm_stat("dex", 16);
        set_skill("parry",80);
        set("max_hp", 400);
        set("hit_points", 400);
        set("max_fp", 400);
	set("force_effect",2);
        set("force_points", 400);
        set_natural_weapon(12, 5, 8);
        set_natural_armor(45, 20);
        set("special_defense", ([ "all" : 10, ]) );
        set("aim_difficulty", ([ "critical" : 10, "vascular" : 4, ]) );
        set ("gender", "male");
        set ("race", "human");
        set_c_limbs(({ "����", "ͷ��", "�Ų�", "�ֱ�"}));
        wield_weapon(SAULIN_OBJ"scoop");
}
