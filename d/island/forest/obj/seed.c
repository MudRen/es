#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Seed of Luoko","���ʵ�����");
    add("id",({"seed"}) );
    set_short("����");
    set_long(@LONG
�������ʵ����ӣ�һ��Բ��������������ģ������û�뵽�⾹�����ػ��飡
���ǸϿ���취�����ֵ�����԰ȥ�ɣ����Ǭ���ˣ�
LONG
             );
    set("unit","��");
    set("weight",5);
    set("value",({5,"copper"}) );
    set("no_sale",1);
    set("luoko_seed",1);
}

    