#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("bear-snake pill","��ɽ��ת������");
        add( "id" , ({ "pill" }) );
        set_short( "��ɽ��ת������");
        set_long(@C_LONG
����һ�Ű�ɫ��ҩ��,�������е�����ġ���ת����������ɽ���ϲɼ�ʮͷ�����
�ƺ���ʮ�������ߵ��Լ�ǧ���ˡ����ƶ��ɵ�,������ޱ�, ������������������
Ч��
C_LONG  );      
        set("unit","��");
        set("weight",1);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
