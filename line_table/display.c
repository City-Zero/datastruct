



void display(Node *head)
{
    Node *tmp = head->next;
    while(tmp != NULL){
        if(tmp != head->next && tmp->xishu > 0)
            printf("+");
        if(tmp->cishu == 0)
            printf("%d",tmp->xishu);
        else if(tmp->cishu == 1){
            if(tmp->xishu == 1)
                printf("X");
            else if(tmp->xishu == -1)
                printf("-X");
            else 
                printf("%dX",tmp->xishu);
        }
        else{
            if(tmp->xishu == 1)
                printf("X^%d",tmp->cishu);
            else if(tmp->xishu == -1)
                printf("-X^%d",tmp->cishu);
            else 
                printf("%dX^%d",tmp->xishu,tmp->cishu);
        }
        tmp = tmp->next;
    }
}
