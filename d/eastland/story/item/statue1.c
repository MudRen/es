#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("stone statue","ʯ����");
        add( "id" , ({ "statue" }) );
        set_short( "ʯ����");
        set_long(@C_LONG
һ������������ʮ�߳���������̻����Ǹ���̬�����սʿ�������ڸ�һֻҰ��
�������㲻����������Ĥ��(worship)������֮����Ȼ������
C_LONG  );      
        set("unit","��");
        set("prevent_get",1);
}
