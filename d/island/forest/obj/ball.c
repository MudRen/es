#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Spirit Ball","ʥ��ʿԪ��");
    add("id",({"ball","spirit"}) );
    set_short("ʥ��ʿԪ��");
    set_long(@LONG
����ʥ��ʿ��Ԫ��է��֮�£�ֻ��һ��СС�ģ������Ĺ���
������ܽ����ͻ�ʥ��ʿ�Ľ����У������в���˼������鷢��
Ŷ��
LONG
            );
    set("unit","��");
    set("weight",50);
    set("value",({1,"copper"}) );
    set("no_sale",1);
    set("ball",1);
 }
