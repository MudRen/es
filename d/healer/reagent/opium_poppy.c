// OpiumPoppy.c		���
//
//			Lilia

#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Opium poppy", "���");
    add("id", ({"opium", "poppy"}));
    set_short("���");
    set_long("��仨���Ǵ�˵�е���ڻ�����������Ʒ��ԭ�ϡ�\n");
    set("ident", "OPIUM");
    set("unit", "��");
    set("weight", 4);
    set("no_sale", 1);
}

