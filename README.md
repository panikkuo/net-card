\documentclass[a4paper,12pt]{article}
\usepackage[a4paper,margin=1in]{geometry}
\usepackage{longtable}
\usepackage{hyperref}
\usepackage{booktabs}
\usepackage{listings}
\usepackage[utf8]{inputenc}
\lstset{basicstyle=\ttfamily,breaklines=true}
\title{Документация API NetCard}
\author{Команда NetCard}
\date{\today}

\begin{document}
\maketitle

\section*{Введение}
API NetCard позволяет регистрировать пользователей, аутентифицировать их и управлять ссылками на социальные сети. В этой документации описаны доступные эндпоинты, форматы запросов и ответов, а также используемые схемы данных.

\section{Схемы данных}
В системе NetCard задействованы три основные сущности:
\begin{itemize}
\item \textbf{users}: зарегистрированные пользователи.
\item \textbf{networks}: доступные типы социальных сетей (например, Twitter, LinkedIn).
\item \textbf{connections}: связи между пользователями и их профилями в соцсетях.
\end{itemize}

\subsection*{users}
\begin{longtable}{@{}lp{10cm}@{}}
\toprule
Поле & Описание \
\midrule
id & Целое число, первичный ключ \
username & Строка, уникальное имя пользователя \
password & Строка, хешированный пароль \
email & Строка, адрес электронной почты \
created_at & Метка времени, момент регистрации \
\bottomrule
\end{longtable}

\subsection*{networks}
\begin{longtable}{@{}lp{10cm}@{}}
\toprule
Поле & Описание \
\midrule
id & Целое число, первичный ключ \
name & Строка, название социальной сети \
\bottomrule
\end{longtable}

\subsection*{connections}
\begin{longtable}{@{}lp{10cm}@{}}
\toprule
Поле & Описание \
\midrule
user_id & Целое число, внешний ключ на \texttt{users.id} \
network_id & Целое число, внешний ключ на \texttt{networks.id} \
url & Строка, ссылка на профиль пользователя \
created_at & Метка времени, момент создания связи \
\bottomrule
\end{longtable}

\section{Эндпоинты API}
Все эндпоинты начинаются с префикса \texttt{/api} и возвращают JSON.

\begin{longtable}{@{}llll@{}}
\toprule
Название & Путь & Метод & Описание \
\midrule
Регистрация пользователя & /api/users/v1/signup & POST & Создать нового пользователя \
Добавление соцсетей пользователя & /api/users/v1/social-networks & POST & Добавить ссылки на соцсети \
Аутентификация & /api/users/v1/login & POST & Авторизация пользователя \
Получение профиля & /api/users/v1/profile/{{userId}} & GET & Получить данные пользователя и ссылки \
Обновление данных пользователя & /api/users/v1/update-user-info & POST & Обновить информацию о пользователе \
Обновление соцсетей пользователя & /api/users/v1/update-user-networks & POST & Изменить ссылки на соцсети \
Список соцсетей & /api/social-networks/v1 & GET & Получить перечень доступных соцсетей \
\bottomrule
\end{longtable}

\subsection{POST /api/users/v1/signup}
\textbf{Описание:} Регистрирует нового пользователя с логином, паролем и электронной почтой.
\textbf{Тело запроса:}
\begin{lstlisting}[language=json]
{
"username": "string",
"password": "string",
"email": "string"
}
\end{lstlisting}
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"id": 123,
"username": "string",
"email": "string",
"created_at": "2025-04-18T12:34:56Z"
}
\end{lstlisting}

\subsection{POST /api/users/v1/social-networks}
\textbf{Описание:} Добавляет новые ссылки на социальные сети для пользователя.
\textbf{Тело запроса:}
\begin{lstlisting}[language=json]
{
"userId": 123,
"networks": [
{ "network": "Twitter", "url": "https://twitter.com/user" },
{ "network": "LinkedIn", "url": "https://linkedin.com/in/user" }
]
}
\end{lstlisting}
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"success": true,
"connections": [ ... ]
}
\end{lstlisting}

\subsection{POST /api/users/v1/login}
\textbf{Описание:} Аутентификация пользователя с возвратом JWT-токена.
\textbf{Тело запроса:}
\begin{lstlisting}[language=json]
{
"username": "string",
"password": "string"
}
\end{lstlisting}
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"token": "jwt-token",
"expires_in": 3600
}
\end{lstlisting}

\subsection{GET /api/users/v1/profile/{userId}}
\textbf{Описание:} Возвращает информацию о пользователе и его ссылки на соцсети.
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"username": "string",
"email": "string",
"networks": [
{ "network": "Twitter", "url": "https://twitter.com/user" },
{ "network": "LinkedIn", "url": "https://linkedin.com/in/user" }
]
}
\end{lstlisting}

\subsection{POST /api/users/v1/update-user-info}
\textbf{Описание:} Обновляет базовую информацию пользователя.
\textbf{Тело запроса:}
\begin{lstlisting}[language=json]
{
"userId": 123,
"username"?: "new_name",
"email"?: "new_email@example.com",
"password"?: "new_password"
}
\end{lstlisting}
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"success": true
}
\end{lstlisting}

\subsection{POST /api/users/v1/update-user-networks}
\textbf{Описание:} Обновляет ссылки пользователя на социальные сети.
\textbf{Тело запроса:}
\begin{lstlisting}[language=json]
{
"userId": 123,
"networks": [
{ "network": "Facebook", "url": "https://facebook.com/user" }
]
}
\end{lstlisting}
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
{
"success": true,
"connections": [ ... ]
}
\end{lstlisting}

\subsection{GET /api/social-networks/v1}
\textbf{Описание:} Возвращает список всех доступных социальных сетей.
\textbf{Пример ответа:}
\begin{lstlisting}[language=json]
[
{ "id": 1, "name": "Twitter" },
{ "id": 2, "name": "LinkedIn" }
]
\end{lstlisting}

\end{document}