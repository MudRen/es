// File: /d/noden/nodania/library.c
// Generated by Roommaker Mon Dec  4 20:05:30 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("诺达尼亚图书馆");
	ob->set_long( @LONG_DESCRIPTION
你现在位於诺达尼亚图书馆的大厅中，触目所及全是各式各样的书
籍、卷轴、文件。有一位图书馆员(librarian) 坐在一张书桌前，你可
问她有关书籍(books) 的借阅规则。往东可以回到诺达尼亚广场。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/square" ]) );
	ob->set( "item_desc", ([ 
		"librarian" : @LONG_TEXT
图书馆员正坐在书桌前翻阅一些文件，你可以问问题，但是最好小声地
问，以免吵到其他的人。

LONG_TEXT
, 
		"books" : @LONG_TEXT
这里到处都是书，核桃木的书架上整整齐齐地排满了各式各样的书籍
与文件，如果你没有图书馆员的协助，恐怕很难找到你想要的书籍。

LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"librarian" : "/d/noden/nodania/monster/librarian" ]) );
	ob->reset();
}
