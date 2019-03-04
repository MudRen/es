#include "../../layuter.h"

inherit MONSTER;

void create()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "Six Poul", "����" );
        add ("id", ({ "draconian", "woman","poul" }) );
        set_short( "����");
        set("unit","λ");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "�������������������ĳ��฾��������СС������������׼û��\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({"%s���������ƴ���%s", "%s��������ͷ��%s��ȥ"}));
        set("chat_chance",10);
        set("chat_output",({
          "����˵����ţ��˵ҪȢ�����ˡ�\n",
          "����˵����˵��ʦ����һ����Ҫ�ľ��ᡣ\n",
          "����˵������սʿ�������˵Ҫ�����ˡ�\n",
          "����˵����˵Ҫ�ҵ��ǿ�����Ҫ����������ϸ��Ѱ�ҡ�\n"
          }));
}
