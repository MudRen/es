#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "�껨Ժ" );
       set_long( @C_LONG_DESC
���ߵ���СԺ������Щ���죬��������Ժ���Ȼû���κη���ֻ����
��\�˿���ɫ��ʯ(stone)�� �ഫ���շ���˵����˵����ʯ��ͷ��Ůɢ��
���컨׹�ػ�Ϊ��ʯ��Ī�Ǿ������ʯͷ�����������͵
C_LONG_DESC
       );
       set("item_desc",([ "stone" : @C_LONG
�㿴�����ʯͷ��������ֻ��һ����ͨ�Ĳ�ʯ��! �治֪��Ϊʲ��������Ҫ֣��
���µİ�������������
C_LONG
       ]));
       set("light", 1);
       set("exits",([
		"east" : SAULIN"pusan_temple",
		"west" : SAULIN"forest7",
       ]) );
       reset();
}

void init()
{
       add_action( "touch_stone", "touch" );
}

int touch_stone(string arg)
{
	if( !arg || arg !="stone" )
		return notify_fail("ιι! �㲻Ҫ����������!\n" );
	if( this_player()->query("quest/elephant") ) {
        tell_object( this_player(), @SHADOW_OUT
������ʯͷ��������������ʹ���Ĳ��������ϰ���ʲ����Ҳû���������е�
һ��ʧ�����ף��ȵȣ������߲ʻ��ƺ���ᶯ��! �찡! ���ʯͷ�ǻ�ģ���
����˫�ַ�������С�İ�ʯͷˤ���ڵأ�ʯͷӦ�����ѣ�����һ�����̣�ǿ��
����ѣ��������������Ҫ���Ŷ����Ѿ��������ˡ������˹�ȥ !

��ͻȻ�е�������ҡ�㣬�����۾�һ����ԭ���������ɰ����������������ʵ�
��ȣ���Ц����Ľ��ͣ��Բ���! ���ڰ�ʯͷ�����ڲ����ȵ���������֪ͨ��
������ �����ó�һ�Ѵ��������ͷ��һ�ã������ι�ȥ�ˡ�
SHADOW_OUT
		);
	}
    else
		tell_object( this_player(), @SHADOW_OUT
������ʯͷ��������������ʹ���Ĳ��������ϰ���ʲ����Ҳû������
SHADOW_OUT
		);
	return 1;
}
