#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(14);
       set_name( "ice toad", "�����");
       add ("id", ({ "toad" }) );
       set_short( "�����");
       set("unit","ֻ");
       set_long(@LONG
    һֻֻ��ָͷ��С����ܡ�͸������������һ�����ʺ�ɫ��ϸ�ƣ��������൱��
������
LONG    );
       set_skill("dodge",100);
       set_natural_weapon(35,10,12);
       set_natural_armor(60,15);
       set_c_verbs(({
         "%s�³�������ͷ��%s���˹���",
         "%s��%s���˹���",
         "%s�߸ߵ�����Ȼ��ײ��%s",
         "%s����һ���ֽУ����һ����������%s",
         }));
       set_c_limbs(({"����","ͷ��","�Ȳ�"}));
}
