#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(13);
       set_name( "silver mollusk", "��������");
       add( "id", ({ "mollusk" }) );
       set_short( "��������");
       set("unit","ֻ");
       set_long(@LONG
һֻ˶�������½��������������������ͷ�����Ŀ�ʼƽ�еĻ����Դ��ۺ��͸����
����һֱ��β���������ĵط���������һ�����ɱ�˪��ɵİ�ɫ��״�ۼ�����������
��������ǰ������ȥ�������̲�ס������Ū��һ����
LONG    );
       set_skill("dodge",90);
       set_natural_weapon(45,5,10);
       set_natural_armor(10,40);
       set_c_verbs(({
         "%s�����Ŀ���%s",
         "%s�ס��%s",
         "%s������%s",
         "%s�³�͸���ķ�����մס��%s",
         "%s����%s",
         }));
       set_c_limbs(({"����","ͷ��","β��"}));
}
