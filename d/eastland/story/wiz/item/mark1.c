#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("archmaster's mark","����");
        set_short( "����");
        set_long(@C_LONG
һ��������С�����ƣ�������С�����ʦ�����桹����֣�ӵ��������ƾͿ�����
�ɳ���ʹ��ˡ�
C_LONG  );      
        set("unit","��");
        set("weight",10);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
