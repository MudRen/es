#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("��ŵ�õ�");
	set_long(
@CLong
���߽�һ���õ�, ӭ��ӳ����������һ�Źžɵ���ľ��̨ (counter)
��һ�����ĵǼǲ� (register) �����ڹ�̨��, һ���ŵ���ҳ�������
���������緭��\����һ�ż򵥵�˵�� (note) �����ڹ�̨�Ե�һ��, ��
��д��һЩ���ס�޵�˵����
    ��̨���Ҳ��᷽��һ��ľ��, ��Χ��ʯǽ�����������Ұ�޵�ͷ, ��
����˵���ù����˵����¸ҵ��¼��������������һ������, ��ߵĻ���
��ʱ��Щ����������, �ұߵĻ����������һ����������Ϣ��
CLong
);

	set("c_item_desc", ([
		"counter"	: @ITEM_COUNTER
�����̨�ɺ�ʵ����ľ�����, ����û���κεĵ���, ����һ�����صĸ�
����ϸ��ľͷ�������ɫ, �㷢����������۵Ĺ�̨�����Ѿ����ϰ���֮
�õ���ʷ��
ITEM_COUNTER
		, "register"	: @ITEM_REGISTER
һ����Ƥ�Ѿ��൱�žɵĲ���, ������ҳ�ǿɻ���, ��������ʵ���Ǻ���
�ÿ��ԡ�����Ӧ��д��һЩס�޵�����, �����ּ��ʲ�, ����ȷ�ϡ�
ITEM_REGISTER
		, "note"	: @ITEM_NOTE
������Ӧ���߽�һ��, Ȼ����ϸ���� (read) ����
ITEM_NOTE
		]) );

	set("exits", ([
		"east"		: HERE"maple_street3",
		"south"		: HERE"corridor1",
		"north"		: HERE"corridor2",
		]));
		
	set( "objects", ([
		"keeper"	: MOB"innkeeper"
	]) );
	reset();
}

void	init()
{
	::init();
	add_action( "read_note", "read");
	add_action( "do_sign", "sign");
	add_action( "do_buy", "buy");
}

int	read_note(string s)
{
	if (!s)	return 0;
	if (s=lower_case(s) != "note")	return 0;
	write( @NOTE_MSG
��ס����֪��
    �������ס�޵Ļ�, ������ڵǼǲ���ǩ��������� (sign name on 
register)�� �һ��������Ǯ������һ��Կ��, ��������¥�Ϳ����ߵ���
�ķ��䡣�ڷ������������Ϣ (rest) ����˯��(sleep) �Իָ�����, ��
����Ϣ����, ���뿪����, �������Ҷ��ְ������ȥ��
    ����һ��ļ۸��� 200 ������, ���⻹���Żݵ���������, 3200 ��
����һ�š��������Ҫ�Ļ�, ֱ�Ӹ����� (buy silver card)
                                                        ���ŵ��
NOTE_MSG
	);
	return 1;
}

int	do_buy(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "silver card"	:
			if (!this_player()->debit( "silver", 3200))	
				return notify_fail( "�����Ϳڴ�, ����Ǯ����\n");
			clone_object(OBJ"silver_card")->move(this_player());
			printf("%s", "�ϰ�����Ǯ, ����һ����ɫ�Ŀ�Ƭ��\n");
			return 1;
		default	:
			return 0;
	}
}

int	do_sign(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "name on register"	:
			if (!this_player()->debit( "silver", 200))	
				return notify_fail( "�����Ϳڴ�, ����Ǯ����\n");
			clone_object(OBJ"tavern_key")->move(this_player());
			printf("%s", "�ϰ�����Ǯ, ����һ��СԿ�ס�\n");
			return 1;
		default	:
			return 0;
	}
}
