inherit "/std/board/bboard";

void create()
{
    ::create();
    set_attic_dir("/d/std/data/attic");
    set_save_dir("/d/std/data");
    set_save_file("irc_board");
    set_location("d/std/IRC/lobby") ;
    set("short.text", "chatroom board");
    set("long.text", "This is a board for chat room. You can leave suggestions here as well. Use help board for help on usage.\n");
    set("c_short.text", "���������԰�");
    set("c_long.text", "����, ��ˮ�ӽ���塣��ϸ�÷���ο� help board��\n");
}
