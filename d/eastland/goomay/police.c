#include "goomay.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "����" );
        set_long(
@LONG
�����ǲ�������Ϣ�참�ĵط���������춳��а���������룬���Բ���Ҳ��
�ر�࣬����ֻҪ����ÿ����������Ϊ�˱������ϣ������ɸ��س����������
æ�����Բ�ͷ�����ξ͸������ˡ��������εĹ�÷���ܲ�ͷ���˳ơ�׷��ߡ���
�η�ӥ����һ���������̱ƹ����������£�����û��ǹԹԵ�������ɡ�
LONG
        );
        
        set( "exits", ([ 
                "east" : Goomay"jail",
		"west" : Goomay"office",
        ]) );
        set( "objects", ([
                "master" : Mob"chief_cop",
        ]) );

      create_door("east","west",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "locked",
		"lock"    : "JAIL_DOOR",
                ]) );


        reset();
}

