
#include "../takeda.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(2);
        set_name( "guest","ʳ��" );
        set_short( "ʳ��");
        set("unit","λ");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",2);
        set_long(
           "����һ��Ľ�����֮��������ʳ�ͣ����������ζ��������ʳ��...\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({"%s���������ƴ���%s", "%s��������ͷ��%s��ȥ" }));
        set("chat_chance", 7);
        set("chat_output",({
          "ʳ��˵����˵�����䳡����һ����ֵĺ�������....\n",
          "ʳ��˵���Ա鶫����½��������ҵĶ�����óԡ�\n",
          "ʳ��˵����˵�ʶ��ĳ������Ҫ�����ѵ�û�����ڴ�ɨ(sweep)������\n",
          "ʳ�ʹ�У��ϰ壬������ţ�⣬�ٶ��е�С�ˡ�\n",
          "ʳ����������Ķ��ӣ�һ������δ��������....\n"
        }));
}
