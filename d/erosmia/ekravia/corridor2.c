#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("����һ��");
	set_long(
@CLong
���������ȵ�ת��, һ��¥�� (stairs) ͨ��¥�ϵĿͷ�����¥����
�������������һ�ȴ��� (window), ͸���������Կ�������Ĵ�֡�
    ���Ͽ��Իص��ùݵĴ�����
CLong
);

	set( "c_item_desc", ([
		"stairs"	: @ITEM_STAIRS
�㿴��һ��ľͷ����¥��, һ�߿���ǽ��, ��һ������һ������, �м�
Լ�п������˲��еĿ�ȡ������¥�ݿ���ͨ��¥�ϵĿͷ�, ¥������
�Ŀռ��򱻷�����, ���濪��һ��ľ�� (wooden door)��������Ӧ����
һ��С�����ҡ� 
ITEM_STAIRS
		, "window"	: @ITEM_WINDOW
����һ��ľ��, ���Է����������ƿ�����̨�������һ��������, ��
��������ȥ, ����Կ�������Ĵ����������������ˡ�
��ע�⵽�����ϵ����ƺ����˻��ˡ�
ITEM_WINDOW
	]) );

	set("exits", ([
		"up"		: HERE"corridor2",
		"south"		: HERE"tavern",
		]));
	set("pre_exit_func", ([
		"up"		: "make_bedroom",
		]) );
}

int		make_bedroom()
{
	object	ob;
	object	bedroom;
	
	ob = present( "copper key", this_player() );
	if (ob && (base_name(ob) == OBJ"tavern_key"))
	{
		printf("%s", "������¥, �ҵ�����ķ���, ���ϰ�����Կ�״򿪷��š�\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	ob = present( "silver card", this_player() );
	if (ob && (base_name(ob) == OBJ"silver_card"))
	{
		printf("%s", "����¥, �߽��Լ��ķ��䡣\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	printf("%s", "�㻹û������, ��ȥ��Ҳû���á�\n");
	return 1;
}