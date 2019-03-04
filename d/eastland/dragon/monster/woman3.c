
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "aunt cheng", "�Ŵ���" );
        add ("id", ({ "draconian", "cheng","aunt" }) );
        set_short( "�Ŵ���");
        set("unit","λ");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "�Ŵ�����ϲ�����˳��̣�����ϲ��ɢ��ҥ�ԡ�\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({"%s���������ƴ���%s,%s��������ͷ��%s��ȥ"}));
        set("chat_chance",5);
        set("chat_output",({
          "�Ŵ���˵����ţ��˵Ҫȡ�����ˡ�\n",
          "�Ŵ���˵���ڼҵ�С������˵�ǰ׳ա�\n",
          "�Ŵ���˵�� ��˵С��Ů����һ��Ů�ޡ�\n",
          "�Ŵ���˵����˵֣�󻧲���һƿ����þơ�\n",
          "�Ŵ���˵����˵���˹�����һ�������������ˣ��κ���Ʒ������ĳ�����\n" 
          }));
}
