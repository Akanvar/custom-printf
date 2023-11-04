{
        list_t *env1 = new_node("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:
                        /usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
        list_t *env2 = new_node("HOME=/home/vagrant");
        list_t *env3 = new_node("LOGNAME=vagrant");

        info_t info;
        info.env = env1;
        env1->next = env2;
        env2->next = env3;
        env3->next = NULL;
}
