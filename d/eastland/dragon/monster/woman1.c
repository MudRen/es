
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "Shan cool", "����" );
        add ("id", ({ "draconian", "shan", "cool", }) );
        set_short( " ����");
        set("unit","λ");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "���������������������ˣ�������СС�����¶��Ǿ����������ġ�\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({"%s���������ƴ���%s", "%s��������ͷ��%s��ȥ" }));
        set("chat_chance", 10);
        set("chat_output",({
          "����˵�����������̫̫��·����һ�ӻ�ˤ�ϵ����ȣ�����̫���ˡ�\n",
          "����˵���������ɭ�ֳ��ֵ�һ�����ع�������Ȼ���ƶ�λ�ã�����������������˵���ǿøߴ�ǿ׳������\n",
          "����˵����̫̫�������������һ����С��\n"
        }));
}
