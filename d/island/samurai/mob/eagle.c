#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Eagle Nanaruha ", "��ӥ ����³��" );
        add ("id", ({ "eagle","nanaruha"}) );
        set_short( "Eagle Nanaruha","��ӥ ����³��");
        set("unit","λ");
        set_long(@AAA
����³����һֻ���͵Ĵ�ӥ��ӵ��ǿ���ĳ��������צ�������ȿ�¶¶�ĺ�
�ѣ����������ȿ�¶¶�����ԣ���
AAA
        );
        set("hit_points",350);
        set("max_hp",350);
        set ("natural_weapon_class1", 50);
        set ("natural_min_damage1",15);
        set ("natural_max_damage1",45);
        set ("natural_armor_class", 65);
        set("natural_defense_bonus",18);
        set_c_limbs(({"����","ͷ��","צ��","���"}));
        set_c_verbs( ({"%s���¸��壬ײ��%s","%s�ü����צ��ץ��%s","%s�ó������%s"}) );
       
}