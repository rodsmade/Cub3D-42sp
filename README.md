# Cub3D
A first-person perspective 3D game written in C.

## Como implemento uma feature (desenvolvimento local)
### Organização do Repositório

Atualmente trabalhamos com duas branches protegidas (**`main`** e **`development`**), o que significa que alterações nestas branches só podem ser feitas via *pull requests* (PRs). As demais branches seguem um padrão de nomenclatura específico.

> :memo: Alguns times trabalham com aprovação de PRs por outra pessoa que não é a que fez a PR. Outra prática comum é criar um script que automatiza a execução de testes no código submetido para PR, e só permite que a PR seja aprovada mediante todos os testes passarem.

A branch `development` é a branch mais estável e que contém a versão mais atual do CRM. Idealmente, toda nova alteração do CRM deve partir de uma cópia da development (git checkout -b <feat-nova-branch>). Uma vez concluído o desenvolvimento da nova alteração, faz-se então um pedido de pull request para incorporar a nova alteração à development. E, afinal, a development será incorporada à main por intermédio de uma branch temporária de lançamento (release). Mais sobre isso logo menos.

A branch `main` é a branch que tem todas as configurações necessárias para que o CRM rode dentro do servidor da 42. Isto inclui rotas e credenciais de produção, e a containerização do back, do front e do banco de dados. A main é uma branch protegida e a única forma de fazer alterações à main deve ser via pull request.

As demais branches seguem os seguintes padrões de nomenclatura:

| Padrão | Função | Exemplos |
| :--- | :--- | :--- |
| `feature-um_nome_de_feature` | Para implementar novas funcionalidades | `feature-toast_component`<br>`feature-results_page_redesign` |
| `hotfix-um_nome_de_bug` | Para corrigir bugs e erros | `hotfix-expired_credentials`<br>`hotfix-cadet_tags_state` |
| `refactor-nome_da_refatoração` | Para refatorar código já funcionando | `refactor-components_organisation`<br>`refactor-toast_portal` |
| `release-vX.X` | Para realizar uma nova implantação | `release-v1.0`<br>`release-v1.6` |
