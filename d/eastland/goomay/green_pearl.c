#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short("����¥" );
        set_long(
@LONG
�����Ǵ����Ǯ�����ص�Ϊ���ĳ�檣������������һ��С¥��
װ��ȴһ�㶼�����������ص�ǽ���Ϲ�������ˮīɽˮ����������
��ʹ������ǰ���Ե�ʮ�ֽྻ���š������������������һ����
���ܶ���������ˡ�
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"rich_house",
		"up"   : Goomay"green_pearl2",
        ]) );
        set( "objects", ([
                "maid1" : Mob"maid",
		]));
        set( "pre_exit_func", ([
                "up" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if(!this_player()->query_temp("give_pearl") && !wizardp(this_player()))
        {
                tell_object(this_player(),
                "�Ů��������������ǰ˵�����������������һ����ò���������Ҵ��˼Ҽ��� !!��\n");
		return 1;
	}
	else
	return 0;
}
