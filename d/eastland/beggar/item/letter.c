#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("a white letter","�ż�");
        add( "id" , ({ "a white letter" }) );
        set_short( "�ż�");
        set_long(@C_LONG
����һ���ɫ���ż�,����д��ƽ������Ƭ����,�������ֵ��˿��ǿ�������
C_LONG  );      
        set("unit","��");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
