#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
        set_name("chi-eu's corpse","����ȡ��ġ���");
        add( "id" , ({ "corpse" }) );
        set_short( "����ȡ��ġ���");
        set_long(@C_LONG
���ǡ���ȡ��ġ��塣��ʱ�Ƶۺ���ȴ�ս�����ս�������ͱ����ڽ���ԣ���
�������������������ʿ��Ҫ���˵���ȴ����������;���������������Ͳ�����
֮��
C_LONG  );      
        set("unit","��");
        set("weight",500);
        set("no_sale",1);
        set("chicorpse",1);
        set("value", ({1, "silver"}) );
}
