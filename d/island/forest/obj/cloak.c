#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Hawk Cloak","��ӥ����");
    add("id", ({ "cloak","soup" }) );
    set_short("��ӥ����");
    set_long(@C_LONG
�����������ҳ�Աս��ʱר�õ����硣�����崩�ϴ�����ʱ�����������ᱶ��������
����ʵ����ɣ������������˻����������Գ�Ϊ���������ɲ�ҪС���������Ŷ
���������ռ������ġ���ӥ����֯�ɵ�Ŷ��
C_LONG
           );
    set("unit","��");
    set("type","cloak");
    set("material","leather");
    set("armor_class",8 );
    set("defense_bonus",4 );
    set("special_defense", (["fire":10,"cold":10,"divide":-20,"poison":-30]) );
    set("weight",100);
    set("value",({1200,"silver"}) );
}
