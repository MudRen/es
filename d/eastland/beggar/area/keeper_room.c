#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "keeper's room", "�ܼҵ�����" );
	set_long(@C_LONG
�����ǹܼһ����������ӡ�������û��ʲ����صĶ���,�տն�������ʾ����
�����ᾫ��춲���֮���,����������˱���ͺ�ƶ��ɡ�ǽ�������м�֧������
��ľ�ƿ;�е��ǿյ��е����ǰ�����; ����������Ӷ����Ե��е㲻̫�������
����߻���һ�ŷ�֯��, �����м����󴩲�������,�����Ů�����õ�, ����ȴ��
��Ů���˵���Ӱ��
C_LONG
	);
	set( "light",1);
	set( "exits", ([
                      "out":DBEGGAR"west4.c"
	]) );
        set( "objects",([
                      "keeper":DMONSTER"keeper.c"
        ]) );              
     reset();
}

