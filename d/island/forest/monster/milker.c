#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(4);
    set_name("Milker","��ţ");
    add("id",({"cow"}) );
    set_short("��ţ");
    set_long(@LONG
�㿴��һֻ���������׵׺ڻ��Ķ���, ���ӻ����������鷿, ��Ȼͷ�ϻ�����
��ֻ��, ���ǿ������ƺ���ʮ����ѱ��ģ��!
LONG
            );
    set("unit","ͷ");
    set_perm_stat("str",5);
    set("hit_points",50);
    set("max_hp",50);
    set_natural_weapon(4,3,5);
    set_natural_armor(15,0);
    set_c_verbs( ({"%s��ǿ�������������%s","%s����ͷ�ϵĽ���%s����"}) );
    set_c_limbs( ({"����","ͷ��","����","β��"}) );
}