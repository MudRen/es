#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "hotal boss", "�ù��ϰ�" );
	add( "id", ({ "boss" }) );
	set_short( "�ù��ϰ�" );
	set_long(@C_LONG
һλ����ơ�ƶǵ������ˣ�����Ц������վ�ڹ�̨���к����ˡ�
C_LONG
        );
	set( "gender", "male" );
        set( "no_attack",1);
        set( "inquiry", ([
            "golden_older":"@@ask_older",
                  "killer":"@@ask_killer"
        ]) );
}
void ask_older(object asker)
{
tell_room(environment(),@LONG

�ϰ�˵�������ˣ�Ī�����ʵ��Ǿ�ס�ڳ�����Ǹ�Ƣ���Źֵ����˼ң�
�����������������ȥ��������ô��ر�Ķ���(special_things)ȥͶ
          �����ģ���Ϊ����ƽ��ռ������챦�ˡ�
����
LONG
   );
}

void ask_killer(object asker)
{
write(@LONG
�ϰ�˵�����̿ͣ���˵��������Ĵ̿ͣ���ʲ�ᶼ��֪��ร�������ֻ
��������������һ����Ӱ(shadow)��ǽ������

LONG
   );
}