#include "../tsunami.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Little wolf","СҰ��");
    add("id",({"wolf"}) );
    set_short("СҰ��");
    set_long(@LONG
����һֻСҰ�ǣ���ϸһ��������������ϲ���أ���������������ƺ�����������Ȥ
�ģ����ϵ�ҡ��β�ͣ�����Ҫ�������ˣ�أ�
LONG
            );
    set("unit","ֻ");
    set("alignment",-100);
    set("weight",100);            
    set_natural_weapon(5,5,10);
    set_natural_armor(10,5);
    set_c_verbs( ({"%s��������%s","%sŬ��ҧ��%s"}) );
    set_c_limbs( ({"ͷ��","����","ƨ��","β��"}) );
}