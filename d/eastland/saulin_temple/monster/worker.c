#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(6);
        set_name( "worker", "����" );
        add ("id", ({ "worker" }) );
        set_short("����");
        set("unit","λ");
        set_long("����һ���ڲ�԰�����ĳ�����ȫ�������������Ŭ��������\n");
        set("alignment",100);
        set("wealth/silver",20);
        set_perm_stat("str", 10);
        set_perm_stat("dex", 9);
        set_natural_weapon(8,2,5);
        set_natural_armor(30, 12);
        set ("gender", "male");
        set ("race", "human");
        set ("chat_chance",20);
        set ("chat_output",({
        "����˵���������һЩ��֪���Ķ���������԰���ң������ᡣ\n",
        }));
        wield_weapon(SAULIN_OBJ"spud");
}
