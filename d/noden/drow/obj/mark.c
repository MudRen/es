#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("captain's seal","�����ӳ�����");
    add("id",({"seal"}));
    set_short("�����ӳ�����");
    set_long(
@C_LONG
����һö�����ӳ��Ļ��£���ͭƬ���鱦ʯ��ɣ��������������
�ޱȵ����ġ�
C_LONG
            );
    set("unit","ö");
    set("weight",20);
    set("value", ({ 100, "silver" }));
    set( "no_sale",1);
}                                 
