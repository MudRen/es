#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Thunder Whip","�����");
    add("id",({"whip"}) );
    set_short("�����");
    set_long(@C_LONG
��˵�����Ϲ�����³�����ֵ���ޡ�
C_LONG
            );
    set("unit","��");
    set("type","whip");
    set("weapon_class",13);
    set("min_damage",5);
    set("max_damage",10);
    set("second",1);
    set("value",({ 350,"silver"}) );
    set_c_verbs( ({"��%s��������������%sֱ����ȥ",
       "��%s˦�����಻����ԲȦȦ����%s","��%s�ڵ������߲�����ͻȻɨ��%s"}) );
}    