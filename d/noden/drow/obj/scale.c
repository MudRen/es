#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("scale","��������");
    set_short("��������");
    set_long(
@C_LONG
����ö���������������ۣ����������ɫ���ܷ����κι��ߣ�
���ı�Ե���˵��������ƺ��ܸ����κζ�������������״������
���ƺ��ܷ�(put)��ĳ����
C_LONG
            );
    set("unit","ö");
    set("weight",15);
    set("value", ({ 10, "silver" }));
    set ("no_sale", 1);
}
