// ghost gardener

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("ghost", "���");
    set_short("���");
    set_long(@C_LONG
����ģ���İ�Ӱ�������ƺ�����Сˮư�ͻ���������ǰ������������԰
���ɣ�������ʲ��ԭ�����������ﶺ��û���κ���ȥ�����أ������Ĺ۲�һ
�»���Щ�ջ�Ҳ˵������
C_LONG
	    );
    set("chat_chance", 15);
    set("chat_output", ({"���˵��ǰͷ��������������Թ������ǿ��ͷ��!\n"}));
    set("no_attack", 1);
    set("gender", "male");
    set("race", "undead");
    set("unit", "λ");
}
 

