#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(5);
        set_name( "greeting monk", "֪��ɮ" );
        add ("id", ({ "monk" }) );
        set_short("֪��ɮ");
        set("unit","λ");
        set_long(@C_LONG
����һλ����ĺ��У���Ϊû�������书\�Ͳ������������ģ���ȴ��һ������
�Ƶ����죬����ֻ�ܸ���Ӵ��������ֵ���ͺ��������
C_LONG
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set_natural_weapon(8, 5, 9);
        set_natural_armor(20, 16);
        set("max_hp", 200);
        set("hit_points", 200);
        set("special_defense", ([ "all" : 5, ]) );
        set("aim_difficulty", ([ "critical" : 15, "vascular" : 30, ]) );
        set_skill("dodge",40);
//		set("defense_type","dodge");
        set_skill("unarmed",70);
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%sһָ����%s", "%sһ������%s", "%s��ȭ����%s" }));
        set_c_limbs(({ "����", "ͷ��", "�Ų�", "�ֱ�" }));       
#include <replace_mob.h>
}
